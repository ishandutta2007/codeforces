#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int dp[100000 + 100], a[100000 + 100];


int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
    int n, k = 0;
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> a[i];
    int manfia = 0, mosbata = 0;
    for (int i = 1; i < n; i++){
        if (a[i] <= 0)
            manfia ++;
        if (a[i - 1] >= 0)
            mosbata ++;
    }
    if (a[0] >= 0)
        manfia ++;
    if (a[n - 1] <= 0)
        mosbata ++;
    dp[0] = manfia;
    dp[n - 1] = mosbata;
    for (int i = 1; i < n - 1; i++){
        int p = 0;
        if (a[i] > 0)
            p = 1;
        if (a[i] < 0)
            p = -1;
        dp[i] = dp[i - 1] + p;
    }
    int ans = 1000000;
    for (int i = 0; i < n; i++){
        ans = min(ans, dp[i]);
    }
    fout << ans << endl;
}