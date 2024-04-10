#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class tree {
    public:
        char operation;
        int value;
        tree* leftChild;
        tree* rightChild;
        int size;

        tree(vector<int> nums) {
            size = nums.size();

            if (nums.size() == 1) {
                operation = '|';
                value = nums[0];
            } else {
                vector<int> upper;
                upper.resize(nums.size()/2);
                for (int i = 0; i < upper.size(); i++) upper[i] = nums[upper.size() + i];
                nums.resize(nums.size()/2);
                leftChild = new tree(nums);
                rightChild = new tree(upper);

                if (leftChild->operation == '|') {
                    operation = '^';
                    value = leftChild->value | rightChild->value;
                } else {
                    operation = '|';
                    value = leftChild->value ^ rightChild->value;
                }
            }
        }

        void edit(int i, int val) {
            if (size == 1) {
                value = val;
            } else {
                if (i > size/2) {
                    rightChild->edit(i - size/2, val);
                } else {
                    leftChild->edit(i, val);
                }

                if (leftChild->operation == '|') {
                    value = leftChild->value | rightChild->value;
                } else {
                    value = leftChild->value ^ rightChild->value;
                }
            }
        }
};

int getV(vector<int> nums);

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums;
    nums.resize(pow(2,n));
    for (int i = 0; i < nums.size(); i++) cin >> nums[i];

    tree* t = new tree(nums);

    for (int querie = 0; querie < m; querie++) {
        int p, b;
        cin >> p >> b;

        t->edit(p, b);
        cout << t->value << "\n";
    }
}