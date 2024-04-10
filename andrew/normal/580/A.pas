var
 a,x,i,j,n,sc,msc:longint;
begin
 readln(n);
 read(x);
 inc(sc);
 for i:=2 to n do
 begin
  read(a);
  if a<x then begin if sc>msc then msc:=sc; sc:=0; end;
  inc(sc);
  x:=a;
 end;
 if sc>msc then msc:=sc;
 writeln(msc);
end.