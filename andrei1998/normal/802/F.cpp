#include <iostream>
#include <cmath>

using namespace std;

int v[250];

double getUniformProb(int P) {
    double ans = 250 * log(1.0 / (2 * P + 1));
    return ans;
}

double fact[2001];
double getPoissonProb(int P) {
    double ans = 0;
    for (int i = 0; i < 250; ++ i)
        ans += (v[i] + P) * log(P) - P - fact[v[i] + P];
    return ans;
}

void test() {
    int maximum = -1E9, minimum = 1E9;
    for (int i = 0; i < 250; ++ i) {
        cin >> v[i];
        maximum = max(maximum, v[i]);
        minimum = min(minimum, v[i]);
    }

    int bestP = 0;
    double best = -1E18;
    string bestType;

    for (int i = 1; i <= 1000; ++ i) {
        //Uniform
        if (minimum + i >= 0 && 2 * i >= maximum + i) {
            double val = getUniformProb(i);
            if (val > best) {
                bestP = i;
                best = val;
                bestType = "uniform";
            }
        }

        //Poisson
        if (minimum + i >= 0) {
            double val = getPoissonProb(i);
            if (val > best) {
                bestP = i;
                best = val;
                bestType = "poisson";
            }
        }
    }

    cout << bestType << '\n';
}

int main()
{
    for (int i = 2; i <= 2000; ++ i)
        fact[i] = fact[i - 1] + log(i);

    int T = 0;
    cin >> T;

    while (T --)
        test();
    return 0;
}