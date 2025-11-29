# codeforces
- Scraped using https://github.com/Mohd-3/CodeRetriever
- Do not delete `downloaded` and `errors` files as they act as scrape control.

- Scraped using https://github.com/ishandutta2007/CPScraper
- Do not delete `downloaded` and `errors` files as they act as scrape control.

The steps to do a sparse clone are as follows:
```
mkdir codeforces
cd codeforces
git init
git remote add origin https://github.com/ishandutta2007/codeforces
```

This creates an empty repository with your remote, and fetches all objects but doesn't check them out. Then do:
```
git config core.sparseCheckout true
```

Now you need to define which files/folders you want to actually check out. This is done by listing them in `.git/info/sparse-checkout`, eg:

```
echo "README.md" >> .git/info/sparse-checkout
echo "tourist" >> .git/info/sparse-checkout
echo "benq" >> .git/info/sparse-checkout
```

only pulls root folder:
```
git pull --depth=1 origin main
```

## To learn more about partial checkouts:

https://unix.stackexchange.com/questions/233327/is-it-possible-to-clone-only-part-of-a-git-project


>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577

