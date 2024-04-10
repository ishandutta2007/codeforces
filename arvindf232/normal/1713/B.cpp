#include <bits/stdc++.h>
using namespace std;

int main(int argc,char* argv[]){
    int tc;
    cin >> tc;

    for(int i = 0; i < tc; i++  ){
        int n;
        cin >> n;
        vector<int> arr;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            arr.emplace_back(x);
        }
        int last = -1000000727;
        bool down = false ;


        for(int j = 0;j < n; j ++){
            int here = arr[j];
            if(here == last){
                continue;
            }
            if(here < last){
                if(down){

                }else{
                    down = true;
                }
            }else{
                if(down){
                    cout << "NO \n";
                    goto done;
                }
            }
            last =here;
        }
        cout << "YES \n";
        done:;
    }


}