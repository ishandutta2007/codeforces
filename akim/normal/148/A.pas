var a,b,c,d,e,i,s:longint;
begin
 readln(a,b,c,d,e);
 for i:=1 to e do if (i mod a=0)or(i mod b=0)or(i mod c=0)or(i mod d=0) then inc(s);
 writeln(s);
end.