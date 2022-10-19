using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


struct poll { 
	ll x, y; 
	poll(){}
	poll(ll x, ll y) : x(x), y(y) {}
	poll operator + (const poll &p) const { return poll(x+p.x, y+p.y); }
	poll operator - (const poll &p) const { return poll(x-p.x, y-p.y); }
	poll operator * (ll c) const { return poll(x*c, y*c); }
	bool operator == (const poll &p) const { return x == p.x && y == p.y; }
	bool operator < (const poll &p) const { return (x==p.x) ? y<p.y : x<p.x; }
};

pair<poll, pair<ll, ll> > pivot;


ll dot(poll p, poll q) { return p.x*q.x + p.y*q.y; }
ll cross(poll p, poll q) { return p.x*q.y - p.y*q.x; }

bool cmp2(pair<poll, pair<ll, ll> > y, pair<poll, pair<ll, ll> >z){
    poll a = y.first;
    poll b = z.first;
    if(a == b) return false;
    poll p = pivot.first;
	poll q(pivot.first.x + 32361, pivot.first.y+68754);
	if((cross(a-p,a-q)>= 0 && cross(b-p,b-q) >= 0) || (cross(a-p,a-q)<= 0 && cross(b-p,b-q) <= 0)){
		if(cross(a-p,a-q) == 0 && dot(a-p,a-q) > 0) return true;
		if(cross(b-p,b-q) == 0 && dot(b-p,b-q) > 0) return false;
		return cross(b-p,a-p) < 0;
	}
	return cross(a-p,a-q) > 0;
	       
}
ll sidePL(poll p, poll a, poll b) {
        ll d = cross(p-a,b-a);
        if(d == 0) return 0;
        return (d<0)?-1:1;
}

struct uf {
    vector<ll> rt, sz;

    uf(ll n) {
        rt.resize(n);
        sz.resize(n);
        for (ll i = 0; i < n; i++) {
            rt[i] = i;
            sz[i] = 1;
        }
    }

    ll id(ll x) {
        if (rt[x] == x) return x;
        return rt[x] = id(rt[x]);
    }

    bool join(ll x, ll y) {
        x = id(x);
        y = id(y);
        if (x == y) return false;
        rt[x] = rt[y];
        sz[y] += sz[x];
        sz[x] = 0;
    return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    vector<pair<poll, pair<ll, ll> > > pts;
    for(ll i=0; i<n; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        z--;
        if(i != z){
            pts.push_back({poll(x, y), {z, i}}); //z is current label, i is target label
        }
    }
    if(pts.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    pivot = pts.back();
    pts.pop_back();
    sort(pts.begin(), pts.end(), cmp2);
    vector<pair<poll, pair<ll, ll> > > pts2;
    uf u(n);
    for(ll i=0; i<pts.size(); i++){
        if(sidePL(pivot.first, pts[i].first, pts[(i+1)%pts.size()].first)  == 1){
            for(ll j = i+1; j<pts.size(); j++){
                pts2.push_back(pts[j]);
            }
            for(ll j = 0; j<=i; j++){
                pts2.push_back(pts[j]);
            }
            swap(pts, pts2);
            break;
            //shuffle so that i+1 is first, i is last
        }
    }
   
   
    u.join(pivot.second.first, pivot.second.second);
    vector<pair<ll, ll> > ans;
    for(ll i=0; i<pts.size()-1; i++){
        if(u.join(pts[i].second.first, pts[i].second.second)){

        }else{
            ans.push_back({pts[i].second.second, pts[i+1].second.second});
            swap(pts[i].second.first, pts[i+1].second.first);
            u.join(pts[i].second.first, pts[i].second.second);
        }
    }

    vector<ll> revpts(n);
    for(ll i=0; i<pts.size(); i++){
        revpts[pts[i].second.second] = i;
    }

    for(ll i=0; i<pts.size(); i++){
        ans.push_back({pivot.second.second, pts[revpts[pivot.second.first]].second.second});
        swap(pivot.second.first, pts[revpts[pivot.second.first]].second.first);
    }

    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first+1 << " " << p.second+1 << endl;
    }
    
}