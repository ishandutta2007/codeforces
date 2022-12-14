#include <iostream>
#include <stack>
#include <map>
#include <fstream>

using namespace std;

string mp[60][60];

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    ios_base::sync_with_stdio(false);
    int n, m, k;
    fin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mp[i][j] = '0';
    for (int i = 0; i < k; i++){
        int a;
        fin >> a;
        if (a == +1){
            int q, w;
            fin >> q >> w;
            bool cur = true;
            while (mp[q][w] != "0"){
                w ++;
                if (w > m){
                    q ++;
                    w = 1;
                }
                if (q > n){
                    cur = false;
                    break;
                }
            }
            string s;
            fin >> s;
            if (cur == true)
                mp[q][w] = s;
        }
        if (a == -1) {
            string s;
            fin >> s;
            bool cur = true;
            for (int i = 1; cur == true && i <= n; i++){
                for (int j = 1; j <= m; j++){
                    if (mp[i][j] == s){
                        fout << i << " " << j << endl;
                        cur = false;
                        mp[i][j] = '0';
                        break;
                    }
                }
            }
            if (cur == true){
                fout << -1 << " " << -1 << endl;
            }
        }
    }
}