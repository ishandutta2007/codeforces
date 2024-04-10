#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int inf = 1e9;
const int CNT_STEP = 28;
const int CNT_NUMBERS = 6;
const int MAX_LEN = 20;
const int step[CNT_STEP][CNT_NUMBERS] = {{0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 4},{0, 0, 0, 0, 0, 7},{0, 0, 0, 0, 4, 4},{0, 0, 0, 0, 4, 7},{0, 0, 0, 0, 7, 7},{0, 0, 0, 4, 4, 4},{0, 0, 0, 4, 4, 7},{0, 0, 0, 4, 7, 7},{0, 0, 0, 7, 7, 7},{0, 0, 4, 4, 4, 4},{0, 0, 4, 4, 4, 7},{0, 0, 4, 4, 7, 7},{0, 0, 4, 7, 7, 7},{0, 0, 7, 7, 7, 7},{0, 4, 4, 4, 4, 4},{0, 4, 4, 4, 4, 7},{0, 4, 4, 4, 7, 7},{0, 4, 4, 7, 7, 7},{0, 4, 7, 7, 7, 7},{0, 7, 7, 7, 7, 7},{4, 4, 4, 4, 4, 4},{4, 4, 4, 4, 4, 7},{4, 4, 4, 4, 7, 7},{4, 4, 4, 7, 7, 7},{4, 4, 7, 7, 7, 7},{4, 7, 7, 7, 7, 7},{7, 7, 7, 7, 7, 7}};


int res[CNT_NUMBERS][MAX_LEN];
bool dp[MAX_LEN][CNT_NUMBERS];
int p[MAX_LEN][CNT_NUMBERS];
int a[MAX_LEN];
int sum[CNT_STEP];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	long long n, ans, N;
	int pos, k, t;
	scanf("%d", &t);
	for (int i = 0; i < CNT_STEP; i++)
		for (int j = 0; j < CNT_NUMBERS; j++)
			sum[i] += step[i][j];
		
	for (int tt = 0; tt < t; tt++){
		cin >> n;
// 		n = 1e18 - tt;
		N = n;
		for (int i = 0; i < MAX_LEN; i++, n /= 10)
			a[i] = n % 10;
	
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < MAX_LEN - 1; i++){
			for (int j = 0; j < CNT_NUMBERS; j++){
				if (dp[i][j])
					for (int k = 0; k < CNT_STEP; k++)
						if ((sum[k] + j) % 10 == a[i]){
							dp[i + 1][(sum[k] + j) / 10] = 1;
							p[i + 1][(sum[k] + j) / 10] = k;						
						}
			}
		}
		memset(res, 0, sizeof(res));
		if (dp[MAX_LEN - 1][0]){
			pos = 0;
			for (int i = MAX_LEN - 1; i > 0; i--){
				k = p[i][pos];
				for (int j = 0; j < CNT_NUMBERS; j++)
					res[j][i - 1] = step[k][j];
				pos = pos * 10 + a[i - 1] - sum[k];
				assert(0 <= pos && pos < 5);				
			}
			long long answer = 0;
			for (int i = 0; i < CNT_NUMBERS; i++){
				ans = 0;
				for (int j = MAX_LEN - 2; j >= 0; j--)
					ans = ans * 10 + res[i][j]; 
				cout << ans << " ";
				answer += ans;
			}
			cout << endl;
// 			cerr << "N " << N << " ANS " << answer << endl;
			assert(answer == N);
// 			cout << endl;
		}
		else
			cout << -1 << "\n";
		
	}
	
	
    return 0;
}