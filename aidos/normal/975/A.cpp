#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second

const int inf = (1ll << 30) - 1;
typedef long long ll;

using namespace std;

char tmp[2222];
int main(){
    int n;
    scanf("%d", &n);
    set<int> S;
    for(int i = 0; i < n; i++){
        int x = 0;
        scanf("%s", tmp);
        int m = strlen(tmp);
        for(int j = 0; j < m; j++){
            x |= (1<<(tmp[j] - 'a'));
        }
        S.insert(x);
    }
    cout << S.size();
    return 0;
}