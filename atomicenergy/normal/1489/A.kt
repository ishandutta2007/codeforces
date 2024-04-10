

fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    var v:List<Int> = readLine()!!.split(" ").map{i->i.toInt()}
    var u= mutableListOf<Int>();
    var s = mutableSetOf<Int>();
    for(i in v.reversed()){
    	if(!s.contains(i)) u.add(i);
    	s.add(i);
    }
    u.reverse();
    println(u.size)
    for(i in u){
    	print(i);
    	print(" ");
    }
    
}