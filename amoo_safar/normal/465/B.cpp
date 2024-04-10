#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;

int a[1001];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    for(int i =0;i<n;i++) cin >> a[i];

    ll po = 0;
    ll t = 0;
    ll fl = 0;
    while(po < n){
        if(a[po] == 0)po ++;
        else {
            if(fl == 0){
                fl = 1;
                t++;
                if(po == n-1) break;
                else{
                    if(a[po+1] == 0){
                        fl = 0;
                        po ++;
                        t++;
                    } else {
                        po ++;
                        t++;
                    }
                }
            } else {
                if(po == n-1) break;
                else{
                    if(a[po+1] == 0){
                        fl = 0;
                        po ++;
                        t++;
                    } else {
                        po ++;
                        t++;
                    }
                }
            }
        }
    }
    if(a[n-1] == 0)t--;
    cout << max(0ll,t);
    return 0;

}



/*

           _____           ______              ______        _______________           _______________
          /     \         |      \            /      |      /               \         /               \
         /       \        |       \          /       |     /                 \       /                 \
        /   ___   \       |   |\   \        /   /|   |    /    ___________    \     /    ___________    \
       /   /   \   \      |   | \   \      /   / |   |   |    /           \    |   |    /           \    |
      /   /_____\   \     |   |  \   \    /   /  |   |   |   |            |    |   |   |            |    |
     /               \    |   |   \   \  /   /   |   |   |    \___________/    |   |    \___________/    |
    /    _________    \   |   |    \   \/   /    |   |    \                   /     \                   /
   /    /         \    \  |   |     \      /     |   |     \                 /       \                 /
  /____/           \____\ |___|      \____/      |___|      \_______________/         \_______________/

*/