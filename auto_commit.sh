
while [ $a -lt 10 ]
do
    echo $a
    git add .
    git commit -m legends
    git push
    a=`expr $a + 1`
    echo $a
done
