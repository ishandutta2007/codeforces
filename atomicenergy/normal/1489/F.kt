

fun main(args: Array<String>) {
    var x = readLine()!!.split(" ").map{i -> i.toInt()}
    var n = x[0]
    var m = x[1]
    var k = x[2]
    var vv = readLine()!!.split(" ").map{i -> i.toInt()}
    var v = vv.toMutableList();
    v.reverse();
    var tot = 0;
    var cur = 0;
    var amt = 0;
    for(i in v){
        if(i + cur <= k){
            cur += i;
            tot++;
        }else{
            amt++;
            if(amt != m){
                cur = i;
                tot++;
            }else{
                println(tot);
                amt++;
            }
        }
    }
    if(amt < m){
        println(tot)
    }
}