#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;

ll cnt[2][2];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll n;
    cin >> n ;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < 2 * n; i++){
        cnt[a[i] - '0'][b[i] - '0']++;
    }

    ll n1, n2;
    n1 = 0;
    n2 = 0;
    for(int i = 0; i < 2 * n; i++){
        if(i % 2 == 0){
            if(cnt[1][1] > 0){
                cnt[1][1]--;
                n1++;
            } else {
                if(cnt[1][0] > 0){
                    cnt[1][0]--;
                    n1++;
                } else {
                    if(cnt[0][1] > 0){
                        cnt[0][1]--;
                    } else {
                        cnt[0][0]--;
                    }
                }
            }
        } else {
            if(cnt[1][1] > 0){
                cnt[1][1]--;
                n2++;
            } else {
                if(cnt[0][1] > 0){
                    cnt[0][1]--;
                    n2++;
                } else {
                    if(cnt[1][0] > 0){
                        cnt[1][0]--;
                    } else {
                        cnt[0][0]--;
                    }
                }
            }
        }
    }
    if(n1 > n2) cout << "First";
    else {
        if(n2 > n1) cout << "Second";
        else cout << "Draw";
    }
    return 0;
}



/*

           _____           ______              ______        _______________          _______________
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