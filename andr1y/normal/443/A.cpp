// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    char c;
    set<char> e;
    while(cin>>c){
        if(c>='a'&&c<='z') e.insert(c);
    }
    cout<<e.size();
}