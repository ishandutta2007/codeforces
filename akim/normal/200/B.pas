var n,s,x,i:longint;
begin
 readln(n);s:=0;
 for i:=1 to n do
 begin
  read(x);
  s:=s+x;
 end;
 writeln((s/(100*n)*100):1:6);
end.