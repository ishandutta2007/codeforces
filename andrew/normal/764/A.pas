var 
 a,b,c,sc,i:longint;
begin
 readln(a,b,c);
 for i:=1 to c do if(i mod a=0)and(i mod b=0) then inc(sc);
 writeln(sc);
end.