#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
vector<int> cards[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int tot = 0;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        cards[x].push_back(a);

        tot += x;
    }

    int targ = tot / (N / 2);

    for(int a = 1; a <= 100; a++){
        while(!cards[a].empty()){
            cout << cards[a].back() << " ";
            cards[a].pop_back();

            cout << cards[targ - a].back() << "\n";
            cards[targ - a].pop_back();
        }
    }
}