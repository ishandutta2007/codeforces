#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int N, L, M;
const long long mod = 1000000007;

void assert(bool b, std::string err = "unspecified") {
	if (!b) {
		std::cout << err << '\n';
		exit(1);
	}
}

std::vector<std::vector<long long>> buildMatrix(std::vector<int> occ) {
	assert(occ.size() == M);
	std::vector<std::vector<long long>> res(M, std::vector<long long>(M, 0));
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			res[(i + j) % M][i] = occ[j];
	return res;
}

std::vector<int> input() {
	std::vector<int> in(N);
	for (int i = 0; i < N; ++i)
		std::cin >> in[i];
	return in;
}

std::vector<int> getOcc(const std::vector<int> in) {
	std::vector<int> occ(M);
	for (auto &&c : in)
		++occ[c % M];
	return occ;
}

std::vector<std::vector<long long>> mul(const std::vector<std::vector<long long>> A, const std::vector<std::vector<long long>> B) {
	assert(A[0].size() == B.size());
	std::vector<std::vector<long long>> C(A.size(), std::vector<long long>(B[0].size(), 0));
	for(int i = 0; i < A.size(); ++i)
		for(int j = 0; j < B[0].size(); ++j)
			for (int k = 0; k < A[0].size(); ++k) {
				C[i][j] += (A[i][k] * B[k][j]) % mod;
				C[i][j] %= mod;
			}
	return C;
}

std::vector<std::vector<long long>> pow(std::vector<std::vector<long long>> A, int n) {
	std::vector<std::vector<long long>> res(A.size(), std::vector<long long>(A[0].size(), 0));
	for (int i = 0; i < res.size(); ++i)
		res[i][i] = 1;
	while (n != 0) {
		if (n & 1)
			res = mul(res, A);
		A = mul(A, A);
		n >>= 1;
	}
	return res;
}

std::vector<int> add(const std::vector<int> A, const std::vector<int> B) {
	assert(A.size() == B.size());
	std::vector<int> res(A.size());
	for (int i = 0; i < res.size(); ++i)
		res[i] = A[i] + B[i];
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N >> L >> M;

	std::vector<std::vector<long long>> state(M, std::vector<long long>(1, 0));
	state[0][0] = 1;
	state = mul(buildMatrix(getOcc(input())), state);
	auto in = input();
	state = mul(pow(buildMatrix(getOcc(in)), L - 2), state);
	in = add(in, input());
	state = mul(buildMatrix(getOcc(in)), state);
	std::cout << state[0][0] << '\n';
	return 0;
}