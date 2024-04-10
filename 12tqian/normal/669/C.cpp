#include <bits/stdc++.h>
using namespace std;

int main(){
    long n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<vector<long>> ops;
    for(long i = 0; i<q; i++){
        vector<long> temp;
        long a;
        scanf("%d", &a);
        temp.emplace_back(a);
        if(a == 1){
            long b;
            scanf("%d", &b);
            temp.emplace_back(b);
        }
        else if(a == 2){
            long b;
            scanf("%d", &b);
            temp.emplace_back(b);

        }
        else{
            long b, c, d;
            scanf("%d %d %d", &b, &c, &d);
            temp.emplace_back(b);
            temp.emplace_back(c);
            temp.emplace_back(d);
            }
        ops.emplace_back(temp);
    }
    long arr[n][m];
    for(long a = 0; a<n; a++){
        for(long b = 0; b<m; b++){
           arr[a][b] = 0;
        }
    }
    for(long i = q-1; i>=0; i--){
        vector<long> temp = ops[i];
        if(temp[0] == 1){
            long r = temp[1] - 1;
            vector<long> t;
            for(long x = 0; x<m; x++){
                t.emplace_back(arr[r][x]);
            }
            for(long x = 0; x<m; x++){
                arr[r][x] = t[(x-1+4*m)%m];
            }
        }
        else if(temp[0] == 2){
            long c = temp[1] - 1;
            vector<long> t;
            for(long x = 0; x<n; x++){
                t.emplace_back(arr[x][c]);
            }
            for(long x = 0; x<n; x++){
                arr[x][c] = t[(x-1+4*n)%n];

            }
        }
        else{
            long r = temp[1] - 1;
            long c = temp[2] - 1;
            long x = temp[3];
            arr[r][c] = x;
        }
    }
    for(long i = 0; i<n; i++){
            string str = "";
        for(long x = 0; x<m; x++){
            str += to_string(arr[i][x]);
            str+= " ";
        }
        cout<<str<<endl;
    }
    return 0;
}