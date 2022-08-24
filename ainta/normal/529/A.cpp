#include<stdio.h>
#include<algorithm>
#define N_ 2010000
using namespace std;
char p[2010000], Ans[N_ * 2];
int n, D[1010000], D2[1010000], C[N_], ord[N_], ord2[N_], SA[N_], MM, P[1010000], Pcnt;
int X[N_], Y[N_];
void Suffix_Array(int m){
	int i, L = 2, M, cnt, cc, t;
	for (i = 1; i <= m; i++){
		X[i] = p[i - 1], Y[i] = p[i];
	}
	while (1){
		M = max(m, 256);
		for (i = 1; i <= m; i++)C[Y[i]]++;
		for (i = 1; i <= M; i++)C[i] += C[i - 1];
		for (i = 1; i <= m; i++)ord[C[Y[i]]--] = i;
		for (i = 0; i <= M; i++)C[i] = 0;
		for (i = 1; i <= m; i++)C[X[i]]++;
		for (i = 1; i <= M; i++)C[i] += C[i - 1];
		for (i = m; i >= 1; i--)ord2[C[X[ord[i]]]--] = ord[i];
		for (i = 0; i <= M; i++)C[i] = 0;
		cnt = 0;
		for (i = 1; i <= m; i++){
			if (i == 1 || X[ord2[i]] != X[ord2[i - 1]] || Y[ord2[i]] != Y[ord2[i - 1]])cnt++;
			SA[ord2[i]] = cnt;
		}
		t = cnt + 1, cc = 0;
		for (i = 0; i<Pcnt; i++){
			if (t>SA[P[i] + 1])t = SA[P[i] + 1], cc = 1;
			else if (t == SA[P[i] + 1])cc++;
		}
		if (cc == 1)break;
		if (L >= m)break;
		for (i = 1; i <= m; i++){
			X[i] = SA[i];
			if (i + L > m)Y[i] = 0;
			else Y[i] = SA[i + L];
		}
		L *= 2;
	}
}
int main()
{
	int i, t = 0, SS = 0, MM2, pv, cc = 0;
	gets(p);
	for (i = 0; p[i]; i++);
	n = i;
	for (i = n - 1; i >= 0; i--){
		if (p[i] == '(')t++, SS++;
		else t--, SS--;
		if (t > 0)t = 0;
		D[i] = t;
	}
	t = 0;
	for (i = 0; i < n; i++){
		D2[i] = min(D[i], SS - t + MM);
		if (p[i] == '(')t++;
		else t--;
		if (MM>t)MM = t;
	}
	for (i = 0; i < n; i++)p[i + n] = p[i];
	MM = -99999999;
	for (i = 0; i < n; i++){
		if (MM < D2[i])MM = D2[i];
	}
	for (i = 0; i < n; i++){
		if (MM == D2[i])P[Pcnt++] = i;
	}
	Suffix_Array(2 * n);
	MM2 = 99999999;
	for (i = 0; i < n; i++){
		if (MM == D2[i] && MM2 > SA[i + 1]){
			MM2 = SA[i + 1];
			pv = i;
		}
	}
	for (i = 0; i < -MM; i++)Ans[cc++] = '(';
	for (i = pv; i < n; i++)Ans[cc++] = p[i];
	for (i = 0; i < pv; i++)Ans[cc++] = p[i];
	for (i = 0; i < t; i++)Ans[cc++]=')';
	puts(Ans);
	return 0;
}