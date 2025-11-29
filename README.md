# Codeforces Solutions Archive

This repository is a comprehensive collection of solutions from the competitive programming platform [Codeforces](https://codeforces.com/). It serves as a valuable resource for learning and practicing algorithms and data structures. The solutions are organized by usernames of the Codeforces participants.

This archive is powered by [CPScraper](https://github.com/ishandutta2007/CPScraper), a tool designed to scrape and organize competitive programming solutions.

## Why This Repository?

- **Learn from the best:** Analyze solutions from top-rated competitive programmers.
- **Practice and improve:** Find solutions to problems you're stuck on and learn new techniques.
- **A vast collection:** With thousands of solutions, this is one of the most extensive Codeforces archives available.

## How to Use This Repository

Due to the large size of this repository, it's recommended to perform a sparse checkout to clone only the solutions you need.

### Sparse Checkout Instructions

1. **Create a new directory and initialize a Git repository:**
   ```bash
   mkdir codeforces
   cd codeforces
   git init
   ```

2. **Add the remote origin:**
   ```bash
   git remote add origin https://github.com/ishandutta2007/codeforces
   ```

3. **Enable sparse checkout:**
   ```bash
   git config core.sparseCheckout true
   ```

4. **Specify the folders you want to download.** For example, to download solutions from `tourist` and `benq`:
   ```bash
   echo "README.md" >> .git/info/sparse-checkout
   echo "tourist/" >> .git/info/sparse-checkout
   echo "benq/" >> .git/info/sparse-checkout
   ```

5. **Pull the files:**
   ```bash
   git pull --depth=1 origin main
   ```

For more information on partial checkouts, you can refer to this [Stack Exchange thread](https://unix.stackexchange.com/questions/233327/is-it-possible-to-clone-only-part-of-a-git-project).

## Contributing

Contributions are welcome! If you have solutions you'd like to add, please follow the existing directory structure (organizing by Codeforces username).

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
