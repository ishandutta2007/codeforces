#include <stdio.h>

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int n,m;
int arr[1100][1100];
int rsize[1100], csize[1100];

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1){
                rsize[i]++;
                csize[j]++;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) {
                cnt += (m - j - 1) - (rsize[i] - 1);
                break;
            }
        }
        for(int j = m - 1; j >= 0; j--) {
            if(arr[i][j] == 1) {
                cnt += j - (rsize[i] - 1);
                break;
            }
        }
    }
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(arr[i][j] == 1) {
                cnt += (n - i - 1) - (csize[j] - 1);
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(arr[i][j] == 1) {
                cnt += i - (csize[j] - 1);
                break;
            }
        }
    }

    printf("%d\n",cnt);

    return 0;
}