#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long double ld;
const ld eps = 1e-10;

int t, n;
ld p[300300], q[300300];
struct seg{
	ld x, y;
	seg(ld _x = 0, ld _y = 0){
		x = _x, y = _y;
	}
	seg operator +(seg b){
		seg ret = *this;
		ret.x += b.x, ret.y += b.y;
		return ret;
	}
	seg operator -(seg b){
		seg ret = *this;
		ret.x -= b.x, ret.y -= b.y;
		return ret;
	}
};
bool operator <(seg a, seg b){
	return 1. * a.y * b.x > 1. * a.x * b.y + eps; 
}

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	cout << fixed << setprecision(12);
	while(t--){
		seg L, R;
		cin >> n >> L.x >> L.y;
		R = L;
		rep(i, n)
			cin >> q[i];
		rep(i, n)
			cin >> p[i];
		
		if(L.x < eps && L.y < eps){
			rep(i, n)
				cout << "0\n";
			continue;
		}
		
		multiset<seg> st;
		rep(i, n){
			st.emplace(2. * q[i], -2. * p[i]);
			L = L + seg(-q[i], p[i]);
			R = R + seg(q[i], -p[i]);
			
//			cout << L.x << " " << L.y << "   " << R.x << " " << R.y << ": ";
//			for(auto it = st.begin(); it != st.end(); ++it)
//				cout << it->x << " " << it->y << "; ";
//			cout << endl;
			
			while(L.x + st.begin()->x < eps)
				L = L + *st.begin(), st.erase(st.begin());
			if(L.x < -eps){
				seg lst = *st.begin();
				st.erase(st.begin());
				ld k = (-L.x) / lst.x;
				L.y = L.y + lst.y * k;
				L.x = 0;
				lst.x = lst.x * (1. - k);
				lst.y = lst.y * (1. - k);
				st.insert(lst);
			}
			
//			cout << L.x << " " << L.y << "   " << R.x << " " << R.y << ": ";
//			for(auto it = st.begin(); it != st.end(); ++it)
//				cout << it->x << " " << it->y << "; ";
//			cout << endl;
			
			while(R.y - prev(st.end())->y < eps)
				R = R - *prev(st.end()), st.erase(prev(st.end()));
			if(R.y < -eps){
				seg lst = *prev(st.end());
				st.erase(prev(st.end()));
//				cout << R.y << " " << lst.y << endl;
				ld k = R.y / lst.y;
//				cout << k << endl;
				R.x = R.x - lst.x * k;
				R.y = 0;
				lst.x = lst.x * (1. - k);
				lst.y = lst.y * (1. - k);
				st.insert(lst);
			}
			
//			cout << L.x << " " << L.y << "   " << R.x << " " << R.y << ": ";
//			for(auto it = st.begin(); it != st.end(); ++it)
//				cout << it->x << " " << it->y << "; ";
//			cout << endl;
			
			cout << R.x << "\n";
		}
	}
	
	return 0;
}