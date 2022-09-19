#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;

ll n;

int p[30];
ll poi = 0;

ll mid;
int an;
int solve(ll l,ll r){
    if(l == r){
        cout << l << endl;
        fflush(stdout);
        return 0;
    }
    ll mid = (l + r)/2;
    cout << mid << endl;
    fflush(stdout);
    cin >> an;
    if(an == 0)return 0;
    else{
        if((p[poi] == 1)and(an == 1)){
            poi++;
            poi%=n;
            solve(mid+1,r);
            return 0;
        }
        if((p[poi] == 1)and(an == -1)){
            poi++;
            poi%=n;
            solve(l,mid-1);
            return 0;
        }
        if((p[poi] == -1)and(an == 1)){
            poi++;
            poi%=n;
            solve(l,mid-1);
            return 0;
        }
        if((p[poi] == -1)and(an == -1)){
            poi++;
            poi%=n;
            solve(mid+1,r);
            return 0;
        }

    }

}


int main(){
    ll m;
    int ans;
    cin >> m >> n;
    for(int i = 0;i<n;i++){
        cout << 1 << endl;
        fflush(stdout);
        cin >> ans;
        if(ans == 0) return 0;
        p[i] = ans;
    }
    solve(1,m);
    //fflush(stdout);
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