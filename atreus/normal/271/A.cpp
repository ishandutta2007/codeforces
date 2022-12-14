#include<bits/stdc++.h>

using namespace std;

bool differ(int ny){
    int a[4];
    for (int i = 0; i < 4; i++){
        a[i] = ny % 10;
        ny /= 10;
    }
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 4; j++)
            if (a[i] == a[j])
                return false;
    }
    return true;
}
int main (){
    int y;
    cin >> y;
    int ny = y;
    for (int i = 1; i <= 1000; i++){
        ny = y;
        ny += i;
        if (differ(ny) == true)
            return cout << ny, 0;
    }
}