#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

string a[1000], s[1000];

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, k;
    fin >> n >> k;
    for (int i = 0; i < n; i++)
        fin >> a[i];
    for (int i = 0; i < pow(n, k); i++){
        for (int j = 0; j < pow(n, k); j++){
            bool cur = false;
            for (int d = 0; d < k; d++){
                int l = pow(n, d);
                int x1 = (i / l) % n;
                int y1 = (j / l) % n;
                if (a[x1][y1] == '*'){
                    cur = true;
                    s[i] += '*';
                    break;
                }
            }
        if (cur == false)
            s[i] += '.';
        }
    }
    for (int i = 0; i < pow(n, k); i++)
        fout << s[i] << endl;
}