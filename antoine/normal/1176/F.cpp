#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct Card {
    int cost, damage;
};

const int MxN = (int) 2e5 + 9;
const ll Inf = MxN * (ll) 1e9 + 9;

array<array<ll, 10>, 10> getTransitions(const vector<Card> &cards) {
    array<array<ll, 10>, 10> trans;

    for (int newCounter = 0; newCounter <= 9; ++newCounter) {
        static ll dp[MxN + 9][10][4][2];
        for (int i = (int) cards.size(); i >= 0; --i) {
            for (int counter = 0; counter <= 9; ++counter) {
                for (int cost = 0; cost <= 3; ++cost) {
                    for (int boost = 0; boost <= 1; ++boost) {
                        ll &res = dp[i][counter][cost][boost] = -Inf;
                        if (i == (int) cards.size())
                            res = counter == newCounter ? 0 : -Inf;
                        else {
                            res = dp[i + 1][counter][cost][boost];
                            if (cards[i].cost <= cost) {
                                res = max(res,
                                          dp[i + 1][(counter + 9) % 10][cost - cards[i].cost][boost] + cards[i].damage);
                                if (boost)
                                    res = max(res, dp[i + 1][(counter + 9) % 10][cost - cards[i].cost][false] +
                                                   2 * cards[i].damage);

                            }
                        }
                    }
                }
            }
        }
        for (int oldCounter = 0; oldCounter <= 9; ++oldCounter)
            trans[oldCounter][newCounter] = dp[0][oldCounter][3][newCounter > oldCounter];
    }

    return trans;
}

vector<Card> cards[MxN + 9];
ll dp[MxN + 9][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        cards[i].resize(k);
        for (Card &card : cards[i])
            cin >> card.cost >> card.damage;
    }

    for (int i = n - 1; i >= 0; --i) {
        const array<array<ll, 10>, 10> trans = getTransitions(cards[i]);

        for (int counter = 9; counter >= 0; --counter) {
            ll &res = dp[i][counter] = -Inf;
            for (int newCounter = 0; newCounter <= 9; ++newCounter)
                res = max(res, dp[i + 1][newCounter] + trans[counter][newCounter]);
        }
    }

    cout << dp[0][9];
    return 0;
}