#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize ("Ofast")
#define F first
#define S second
#define endl '\n'
#define pb push_back
#define pf push_front
#define mk make_pair
#define pii pair<int,int>
#define piii pair<int , pii >
#define all(a) a.begin() , a.end()
#define debug(x) cerr<<#x<<' = '<<x<<endl;
#define debugp(x) cerr<<#x<<" = {"<<x.first<<" , "<<x.second<<"}"<<endl;
//////////////////////////////////////////////////
const int N = 250001;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;

int mx1, mx2;
//////////////////////////////////////////////////
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        char c;
        int h, w;
        cin >> c >> h >> w;
        if(c == '+'){
            mx1 = max(mx1 , max(h , w));
            mx2 = max(mx2 , min(h , w));
        }
        else{
            if(max(h , w) >= mx1 && min(h , w) >= mx2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
/*
5 5
6 7 1 2 10
9 11 6 3 12
*/