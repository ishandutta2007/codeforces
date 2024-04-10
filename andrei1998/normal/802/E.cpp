#include <bits/stdc++.h>

using namespace std;

int freq[2500];
mt19937 mt(time(NULL));

void getAvg() {
    memset(freq, 0, sizeof freq);
    int sum = 0;

    //int realP = 1000;
    //poisson_distribution <int> distP(realP);

    int minim = 100000, maxim = -10;
    for (int i = 1; i <= 250; ++ i) {
        int sample;
        cin >> sample;

        //sample = distP(mt);
        //sample = rand() % (2 * realP + 1);

        ++ freq[sample];
        sum += sample;
        minim = min(minim, sample);
        maxim = max(maxim, sample);
    }

    int P = sum / 250;
    int dev = 0;

    for (int i = 0; i <= 2000; ++ i)
        dev += freq[i] * (i - P) * (i - P);
    dev /= 250;

    int v1 = P;
    int v2 = P * P / 3;

    if (abs(v1 - dev) < abs(v2 - dev))
        cout << min(max(P, 10), 1000) << '\n';
    else {
        P = (maxim + minim) / 2;
        cout << P << '\n';
    }
}

int main()
{
    srand(time(NULL));
    int T = 0;
    cin >> T;
    while (T --)
        getAvg();
    return 0;
}