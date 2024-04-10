

fun main(args: Array<String>) {
    var q = readLine()!!.toInt();
    var m = mutableMapOf<String, Int>();
    var l = 0;
    var r = 1;
    for(i in 0..q-1){
        var s = readLine()!!.split(" ");
        if(s[0] == "L"){
            m[s[1]] = l;
            l--;
        }
        else if(s[0] == "R"){
            m[s[1]] = r;
            r++;
        }
        else {
            println(minOf(r-m[s[1]]!!-1, m[s[1]]!!-l-1));
        }
    }
    
}