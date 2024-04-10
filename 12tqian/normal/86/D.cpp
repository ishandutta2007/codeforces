#include<bits/stdc++.h>
using namespace std;

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)
#define ll long long
ll cnt[A], a[N], ans[N], answer = 0;
int change = 0;
struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
	answer -= (cnt[a[position]]*cnt[a[position]]*a[position]);
	cnt[a[position]]++;
	answer += (cnt[a[position]]*cnt[a[position]]*a[position]);
}

void remove(int position) {
    answer -= (cnt[a[position]]*cnt[a[position]]*a[position]);
	cnt[a[position]]--;
	answer += (cnt[a[position]]*cnt[a[position]]*a[position]);
}
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main() {
    fast_io();
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> a[i];


	for(int i=0; i<m; i++) {
        cin >> q[i].L >> q[i].R;
		//scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		cout << ans[i] << endl;
}