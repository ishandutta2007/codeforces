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
    sort (a, a + n);
    if (n == 2){
        if (1.0 * a[1] / a[0] <= 2)
            fout << 0 << endl;
        else
            fout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++){
        int r = n;
        int l = i + 1;
        while (r - l > 1){
            if (1.0 * a[(r + l) / 2] / a[i] > 2)
                r = (r + l) / 2;
            else
                l = (r + l) / 2;
        }
        dp[i] = n - (l - i + 1);
    }
    int ans = 100000;
    for (int i = 0; i < n - 1; i++)
        ans = min(ans, dp[i]);
    fout << ans;
}