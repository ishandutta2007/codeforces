#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int N_ = 4105;
const int M_ = 20005;
const int MAXW = 4105;
const int MAXD = 200505;
vector<int> events[MAXD];
vector<pii> queries[MAXD];
int answer[M_];
int S[N_], C[N_];
int N, P;
int M;

int stkF[N_][MAXW], topF;
int stkR[N_][MAXW], whR[N_], topR;

int main() {
    scanf("%d%d", &N, &P);
    for(int i = 1; i <= N; i++) {
        int d; scanf("%d%d%d", &C[i], &S[i], &d);
        events[d].push_back(i);
        events[d + P].push_back(-i);
    }
    scanf("%d", &M);
    for(int i = 1; i <= M; i++) {
        int t, b; scanf("%d%d", &t, &b);
        queries[t].push_back( pii(b, i) );
    }
    
    for(int day = 1; day < MAXD; day++) {
        for(int idx = 0; idx < events[day].size(); idx++) {
            int e = events[day][idx];
            if(e > 0) {
                // insert
                int s = S[e], c = C[e];
                ++topR; whR[topR] = e;
                for(int i = 1; i < MAXW; i++) {
                    stkR[topR][i] = max(stkR[topR - 1][i], stkR[topR][i - 1]);
                    if(i >= c) stkR[topR][i] = max(stkR[topR][i], stkR[topR - 1][i - c] + s);
                }
            }else {
                // erase
                if(topF == 0) {
                    while(topR > 0) {
                        int e = whR[topR--];
                        int s = S[e], c = C[e];
                        ++topF;
                        for(int i = 1; i < MAXW; i++) {
                            stkF[topF][i] = max(stkF[topF - 1][i], stkF[topF][i - 1]);
                            if(i >= c) stkF[topF][i] = max(stkF[topF][i], stkF[topF - 1][i - c] + s);
                        }
                    }
                }
                
                assert(topF > 0);
                --topF;
            }
        }
        //for(auto q : queries[day]) {
        for(int idx = 0; idx < queries[day].size(); idx++) {
            pii q = queries[day][idx];
            int maxw = q.first;
            int &ans = answer[q.second];
            for(int i = 0; i <= maxw; i++) ans = max(ans, stkF[topF][i] + stkR[topR][maxw - i]);
        }
    }
    
    for(int i = 1; i <= M; i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}