#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
typedef pair<int, int> pii;
 
priority_queue<int, vector<int>, greater<int>> pq;
 
char s[300001];
int p[600000];
int rotn[600000];
int fc[600000];
vector<int> lamp[300000];
int n, k;
 
int find(int a) {
    if (p[a] == -1) return a;
    return p[a] = find(p[a]);
}
 
void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    rotn[a] += rotn[b];
    fc[a] |= fc[b];
    p[b] = a;
}
 
int cal(int a) {
    a = find(a);
    int b;
    if(a >= k) b = find(a-k);
    else b = find(a + k);
 
    if (fc[a]) return rotn[a];
    if (fc[b]) return rotn[b];
    return min(rotn[a], rotn[b]);
}
 
int main() {
    memset(p, -1, sizeof(p));
 
    int t, tt;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
 
    for (int i = 0; i < n; i++) s[i] -= '0';
    for (int i = 0; i < k; i++) {
        scanf("%d", &t);
        rotn[i] = 1;
 
        while (t--) {
            scanf("%d", &tt);
            tt--;
            lamp[tt].push_back(i);
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (sz(lamp[i]) == 1) {
            ans -= cal(lamp[i][0]);
            if (s[i] == 0) fc[find(lamp[i][0])] = 1;
            else fc[find(lamp[i][0] + k)] = 1;
            ans += cal(lamp[i][0]);
        }
        else if (sz(lamp[i]) == 2) {
            ans -= cal(lamp[i][0]);
            if (find(lamp[i][0]) != find(lamp[i][1]) && find(lamp[i][0]) != find(lamp[i][1] + k) && find(lamp[i][0] + k) != find(lamp[i][1])) ans -= cal(lamp[i][1]);
 
            if (s[i] == 1) merge(lamp[i][0], lamp[i][1]), merge(lamp[i][0] + k, lamp[i][1] + k);
            else merge(lamp[i][0], lamp[i][1] + k), merge(lamp[i][1], lamp[i][0] + k);
            ans += cal(find(lamp[i][0]));
        }
        printf("%d\n", ans);
    }
}