#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int NMAX = 100000 + 5;

int v[NMAX];

int freq[1024];
int freq2[1024];

int main()
{
    int N, K, x;
    cin >> N >> K >> x;
    for (int i = 1; i <= N; ++ i) {
        cin >> v[i];
        ++ freq[v[i]];
    }

    for (int i = 1; i <= K; ++ i) {
        memset(freq2, 0, sizeof freq2);

        bool par = true;
        for (int j = 0; j < 1024; ++ j)
            if (freq[j] % 2 == 0) {
                freq2[j] += freq[j] / 2;
                freq2[j ^ x] += freq[j] / 2;
            }
            else {
                if (!par) {
                    freq2[j] += (freq[j] + 1) / 2;
                    freq2[j ^ x] += freq[j] / 2;
                }
                else {
                    freq2[j ^ x] += (freq[j] + 1) / 2;
                    freq2[j] += freq[j] / 2;
                }

                par ^= 1;
            }

        for (int j = 0; j < 1024; ++ j)
            freq[j] = freq2[j];
    }

    int maximum = 0;
    int minimum = 1024;

    for (int i = 0; i < 1024; ++ i)
        if (freq[i]) {
            maximum = max(maximum, i);
            minimum = min(minimum, i);
        }
    cout << maximum << ' ' << minimum << endl;
    return 0;
}