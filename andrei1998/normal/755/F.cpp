#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000000 + 5;

int N, K;
int p[NMAX];
int freq[NMAX];

bool vis[NMAX];

vector <int> cycles;

bitset <NMAX> knap;
int sPart[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++ i)
        cin >> p[i];

    for (int i = 1; i <= N; ++ i)
        if (!vis[i]) {
            int node = i;
            int cnt = 0;
            while (!vis[node]) {
                ++ cnt;
                vis[node] = true;
                node = p[node];
            }

            ++ freq[cnt];
            cycles.push_back(cnt);
        }

    //Maximum
    int maximum = 0;
    int _K = K;
    for (auto it: cycles) {
        it = (it / 2) * 2;
        if (it / 2 <= _K) {
            _K -= it / 2;
            maximum += it;
        }
        else {
            maximum += 2 * _K;
            _K = 0;
            break;
        }
    }

    maximum += _K;
    if (maximum > N)
        maximum = N;

    //Minimum
    knap[0] = 1;
    int cnt = 0;
    for (int i = 1; i <= N; ++ i)
        if (freq[i]) {
            if (freq[i] == 1 || i >= 200) {
                while (freq[i] --)
                    knap |= (knap << i), cnt += i;
            }
            else if (freq[i] > 1) {
                cnt += freq[i] * i;
                for (int j = 0; j <= cnt && j <= K; ++ j) {
                    sPart[j] = knap[j];
                    if (j >= i)
                        sPart[j] += sPart[j - i];
                }

                for (int j = i; j <= cnt && j <= K; ++ j)
                    if (!knap[j])
                        knap[j] = (sPart[j - i] - ((j - i * freq[i] - i >= 0) ? sPart[j - i * freq[i] - i] : 0) > 0);
            }
        }

    int minimum = K + 1;
    if (knap[K])
        minimum = K;
    cout << minimum << ' ' << maximum << '\n';
    return 0;
}