/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int index[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			tmp = index[i];
			index[i] = index[j];
			index[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(arr, index, left, j);
	if (i < right)
		quickSort(arr, index, i, right);

}

int main() {
	int n, m;
	cin >> n >> m;
	int ar[n], index[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		index[i] = i + 1;
	}
	quickSort(ar, index, 0, n - 1);
	int k = m;
	vector<int> ans;
	for(int i = 0; i < n; i++){
		if(k - ar[i] >= 0){
			ans.insert(ans.end(), index[i]);
		}else{
			break;
		}
		k -= ar[i];
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}