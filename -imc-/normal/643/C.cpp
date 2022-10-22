#include <bits/stdc++.h>

using namespace std;

vector<double> s, sInv, mPref;

double cost(int i, int j)
{
    if (j < i) return 0;
    i--; j--;
    assert(i >= 0 && j >= 0);
    if (i == 0)
        return mPref[j];
    
    i--;
    
    return mPref[j] - mPref[i] - s[i] * (sInv[j] - sInv[i]);
}

const int maxK = 55;
const int maxN = 200500;

double F[maxK][maxN];
int P[maxK][maxN];

void fill(int g, int l1, int l2, int p1, int p2) {
    // fill(g,l1,l2,p1,p2) calculates all P[g][l] and F[g][l] for l1 <= l <= l2,
    // with the knowledge that p1 <= P[g][l] <= p2
    // the initial call is fill(g,0,L-1,0,L-1)

    // if l1 > l2, then there's nothing to calculate
    if (l1 > l2) return;

    int lm = (l1 + l2) >> 1;
    // calculate P[g][lm] and F[g][lm]
    P[g][lm] = -1;
    F[g][lm] = 1e18;
    for (int k = p1; k <= p2; k++) {
        double new_cost = F[g-1][k] + cost(k + 1,lm);
        if (F[g][lm] > new_cost) {
            F[g][lm] = new_cost;
            P[g][lm] = k;
        }
    }

    // calculate both sides of lm
    fill(g, l1, lm-1, p1, P[g][lm]);
    fill(g, lm+1, l2, P[g][lm], p2);
}  


int main()
{
    int n, k;
    
#if 1
    scanf("%d %d", &n, &k);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
#else
    n = 10;
    k = rand() % 5 + 1;
    vector<int> a(n);
    for (int& x: a)
        x = rand() % 10 + 1;
#endif
    
    s.resize(n);
    sInv.resize(n);
    mPref.resize(n);
    for (int i = 0; i < n; i++)
    {
        s[i] = (i ? s[i - 1] : 0) + a[i];
        sInv[i] = (i ? sInv[i - 1] : 0) + 1.0 / a[i];
    }
    
    double s = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        m += s / a[i];
        mPref[i] = m;
    }
    
    for (int l = 0; l <= n; l++) {
        F[1][l] = cost(1,l);
        P[1][l] = 0;
    }

    for (int g = 2; g <= k; g++) {
        fill(g, 0, n, 0, n);
    }
    
#if 0
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n; i++)
            printf("F[%d][%d] is %f\n", j, i, F[j][i]);
#endif
    
    printf("%f\n", F[k][n]);
    
#if 0
    for (int groups = 0; groups < k; groups++)
    {
        auto& dNow = d[groups & 1];
        auto& dNext = d[(groups & 1) ^ 1];
        
        int best = groups - 1;
        double mat = 0;
        double S = 0;
        double invSum = 0;
        for (int i = groups; i < n; i++)
        {
            S += a[i];
            mat += S / a[i];
            invSum += 1.0 / a[i];
            
            // [0, best], [best + 1, i]
            while (best + 1 < i && dNow[best + 1] + (mat - invSum * a[best + 1]) <= dNow[best] + mat)
            {
                // minus a[best + 1]
                best++;
                mat -= invSum * a[best];
                invSum -= 1.0 / a[best];
                S -= a[best];
            }
            printf("one best %d\n", best);
            
            dNext[i] = dNow[best] + mat;
            
            {
                double minCan = 1e9;
                int bestIndex = 0;
                for (int j = groups - 1; j < i; j++)
                {
                    double s = 0;
                    double m = 0;
                    for (int k = j + 1; k <= i; k++)
                    {
                        s += a[k];
                        m += s / a[k];
                    }
                    double mExp = cost(j + 1, i);
                    if (dNow[j] + m < minCan)
                    {
                        minCan = dNow[j] + m;
                        bestIndex = j;
                    }
                    printf("%d value %f\n", j, dNow[j] + m);
                    printf("got %f expected %f\n", m, mExp);
                    assert(abs(m - mExp) < 1e-5);
                }
                
                printf("%f %f %d\n", dNext[i], minCan, bestIndex);
                //assert(abs(dNext[i] - minCan) < 1e-6);
            }
        }
        printf("NEXT GROUP\n");
    }
    
    double answer = d[(k + 1) & 1][n - 1];
    cout << fixed << setprecision(12) << answer << endl;
#endif
    
    return 0;
}