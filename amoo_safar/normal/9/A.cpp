#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;

int is_p(int n){
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0)return 0;
    }
    return 1;
}

int pr[1001];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll a,b;
    cin >> a >> b;
    ll m = 6 - max(a, b) + 1;
    cout << m / __gcd(m,(ll) 6) << "/" << 6 / __gcd(m,(ll)6);
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