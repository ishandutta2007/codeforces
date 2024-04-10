

fun main(args: Array<String>) {
    var n = readLine()!!.toInt();
    var v = mutableListOf<String>();
    for(i in 0..n-1){
        var s = readLine()!!;
        v.add(s);
    }
    v.sortBy{it -> it.length}
    var ok = true;
    for(i in 0..n-2){
        var t = v[i]
        var s = v[i+1];
        var test = false;
        
        for(j in 0..s.length-1){
            var th = true;
            for(k in 0..t.length-1){
                if(j+k >= s.length || t[k] != s[j+k]) th = false;
            }
            if(th) test = true; 
        }
        if(!test) ok = false;
    }
    if(!ok) println("NO");
    else{
        println("YES");
        for(s in v) println(s);
    }
    
    
}