#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;


#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int c, n, i, x, cnt;
int m[maxN];
int how[maxN];
int ans = maxN;
int le[maxN];

bool works(int step, int act) {
    
    //cerr << step << ' ' << act << '\n';
    
    while (step > 0) {
        step = min(step, act);
        step = le[step];
        
        if (step == 0) break;
        
        cnt = min(m[step], act / step);
        act -= cnt * step;
        step--;
    }
    
    //cerr << act << '\n';
    
    return act == 0;
}

int main() {
    
    scanf("%d%d", &c, &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        m[x]++;
    }
    
    le[0] = 0;
    for (i = 1; i <= c; i++)
        le[i] = (m[i] > 0 ? i : le[i - 1]);
    
    how[c + 1] = c;
    
    for (i = c; i > 0; i--) {
        how[i] = how[i + 1]; 
        cnt = min(m[i], how[i] / i); 
        how[i] -= i * cnt;
        
        if (how[i] > i) {
            if (!works(i - 1, how[i] - i))
                ans = i;
        }
    }

    
    if (ans == maxN)
        printf("Greed is good");
    else
        printf("%d", ans);
    
    
    
    return 0;
}