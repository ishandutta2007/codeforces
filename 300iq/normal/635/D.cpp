#include <bits/stdc++.h>

using namespace std;

vector <int> arr;
vector <int> block_B;
vector <int> block_A;
int block_size;
int a, b;
int n;

int get_A(int l, int r) {
    if (l >= n) return 0;
    int block_l = l / block_size;
    int block_r = r / block_size;
    int pos_l = l % block_size;
    int pos_r = r % block_size;
    int q_ans = 0;
    for (int i = block_l; i <= block_r; i++)
	q_ans += block_A[i];
    for (int i = 0; i < pos_l; i++)
	q_ans -= min(a, arr[block_l * block_size + i]);
    for (int i = pos_r + 1; i < block_size; i++)
	q_ans -= min(a, arr[block_r * block_size + i]);
    return q_ans;
}

int get_B(int l, int r) {
    if (l >= n) return 0;
    int block_l = l / block_size;
    int block_r = r / block_size;
    int pos_l = l % block_size;
    int pos_r = r % block_size;
    int q_ans = 0;
    for (int i = block_l; i <= block_r; i++)
	q_ans += block_B[i];
    for (int i = 0; i < pos_l; i++)
	q_ans -= min(b, arr[block_l * block_size + i]);
    for (int i = pos_r + 1; i < block_size; i++)
	q_ans -= min(b, arr[block_r * block_size + i]);
    return q_ans;
}

void update(int pos, int x) {
    arr[pos] += x;
    int block = pos / block_size;
    block_A[block] = 0;
    block_B[block] = 0;
    for (int i = 0; i < block_size; i++)
	block_A[block] += min(a, arr[block * block_size + i]);
    for (int i = 0; i < block_size; i++)
	block_B[block] += min(b, arr[block * block_size + i]);
}

int main() {
    int k, q;
    cin >> n >> k >> a >> b >> q;
    arr.resize(n);
    block_size = sqrt(n) + 1;
    while(arr.size() % block_size != 0)
	arr.push_back(0);
    block_A.resize(arr.size() / block_size + 1);
    block_B.resize(arr.size() / block_size + 1);
    while (q--) {
	int g;
	cin >> g;
	if (g == 1) {
	    int D, A;
	    cin >> D >> A;
	    D--;
	    update(D, A);
	} else {
	    int p;
	    cin >> p;
	    p--;
	    int l_1 = 0;
	    int r_1 = p - 1;
	    int l_2 = p + k;
	    int r_2 = n - 1;
	    cout << get_B(l_1, r_1) + get_A(l_2, r_2) << endl;
	}
    }
}