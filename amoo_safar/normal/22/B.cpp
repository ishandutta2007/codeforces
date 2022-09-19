#include<iostream>
using namespace std;
char a[25][25];
int main(){
    int n,m,ma,t;
    ma = 0;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int i2 = i;i2 < n;i2++){
                for(int j2 = j;j2 < m;j2++){

                    t = 0;
                    for(int i3 = i;i3 <= i2;i3++){
                        for(int j3 = j;j3 <= j2;j3++){
                            if(a[i3][j3] == '1'){
                                t++;
                            }
                        }
                    }
                    //cout << i << " " << j << " " << i2 << " " << j2 << " " << t << endl;
                    if((t == 0) and (2*(i2-i+2+j2-j) > ma)) ma = 2*(i2-i+2+j2-j);
                }
            }
        }
    }
    cout << ma;

    return 0;
}