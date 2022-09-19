#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;

ll f[26];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    string s;
	int n = 0, ans = 0;
	while(getline(cin, s)){
        if(s[0] == '+')n++;
        else{
            if(s[0] == '-')n--;
            else{
                for(int i = 0;i<s.size();i++){
                    if(s[i] == ':'){
                        ans = ans + n*(s.size()-1-i);
                        break;
                    }
                }
            }
        }

	}
	cout << ans;
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