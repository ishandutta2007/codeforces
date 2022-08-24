#include <bits/stdc++.h>

using namespace std;

vector<vector<double> > ed;

vector<vector<double> > multiply(const vector<vector<double> > &a, const vector<vector<double> > &b){
	vector<vector<double> > c(a.size());
	for (int i = 0; i < a.size(); i++)
		c[i].resize(b[0].size());
	for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < a[0].size(); k++){
                c[i][j] += (a[i][k] * b[k][j]);
            }
	return c;
}

vector<vector<double> > power(const vector<vector<double> > &a, long long pow){
	if (pow == 0)
		return ed;
	if (pow % 2 == 0){
		vector<vector<double> > v = power(a, pow / 2);
		return multiply(v, v);
	}
    return multiply(a, power(a, pow - 1));
}

double p[128];

int main(){
    double n, k;
	cin >> n >> k;
	for (int i = 0; i <= k; i++)
        cin >> p[i];

	ed.resize(128);
	for (int i = 0; i < 128; i++){
		for (int j = 0; j < 128; j++){
			if (i == j)
				ed[i].push_back(1);
			else
				ed[i].push_back(0);
		}
	}

	vector<vector<double> > matrix(128);
	for (int i = 0; i < 128; i++){
		matrix[i].resize(128);
        for (int j = 0; j < 128; j++)
            matrix[i][i ^ j] = p[j];
	}

	vector<vector<double> > vect(128);
	for (int i = 0; i <= k; i++)
        vect[i].push_back(p[i]);
    for (int i = k + 1; i < 128; i++)
        vect[i].push_back(0);

	vector<vector<double> > ans = power(matrix, n - 1);
	ans = multiply(ans, vect);

	cout << fixed << setprecision(8) << 1.0 - ans[0][0];
}