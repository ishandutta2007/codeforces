#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
struct s3{
    int t1, t2;
    int s, e;
    s3(int t11, int t21, int s1, int e1){
        t1 = t11, t2 = t21, s = s1, e = e1;
    }
};
bool cmp(s3 a, s3 b){
    if(a.t1 != b.t1)
        return a.t1 < b.t1;
    return a.t2 < b.t2;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sa(n), ea(n), sb(n), eb(n);
    for(int i = 0; i < n; ++i)
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    vector<s3> a;
    for(int i = 0; i < n; ++i){
        a.emplace_back(sa[i], 1, sb[i], eb[i]);
        a.emplace_back(ea[i]+1, -1, sb[i], eb[i]);
    }
    sort(all(a), cmp);
    multiset<int> s1, s2;
    for(int i = 0; i < a.size(); ++i){
        if(a[i].t2 == 1){
            if(!s1.empty()){
                if(*s1.rbegin() > a[i].e || *s2.begin() < a[i].s){
                    cout << "NO";
                    return 0;
                }
            }
            s1.insert(a[i].s), s2.insert(a[i].e);
        }else
            s1.erase(s1.find(a[i].s)), s2.erase(s2.find(a[i].e));
    }
    a.clear();
    for(int i = 0; i < n; ++i){
        a.emplace_back(sb[i], 1, sa[i], ea[i]);
        a.emplace_back(eb[i]+1, -1, sa[i], ea[i]);
    }
    sort(all(a), cmp);
    for(int i = 0; i < a.size(); ++i){
        if(a[i].t2 == 1){
            if(!s1.empty()){
                if(*s1.rbegin() > a[i].e || *s2.begin() < a[i].s){
                    cout << "NO";
                    return 0;
                }
            }
            s1.insert(a[i].s), s2.insert(a[i].e);
        }else
            s1.erase(s1.find(a[i].s)), s2.erase(s2.find(a[i].e));
    }
    cout << "YES";
	return 0;
}