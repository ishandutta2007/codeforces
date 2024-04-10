

fun main(args: Array<String>) {
    var n = readLine()!!.toInt();
    var s = readLine()!!;
    var tot = 0;
    var cnt = 0;
    for(c in s){
        if(c == 'x'){
            cnt++;
            if(cnt > 2) tot++;
        }else{
            cnt = 0;
        }
    }
    println(tot);
    
}