var min,x,f,max,n,b:longint;
    c:array[1..30,1..2]of longint;
begin
 min:=0;max:=0;
 readln(n,x);
 for b:=1 to n do
 begin
  readln(c[b,1],c[b,2]);
  min:=min+c[b,1];
  max:=max+c[b,2];
 end;
 if (x>=min)and(x<=max)then 
 begin 
  writeln('YES');
  f:=1;
  while x>min do
  begin
   while (c[f,1]<c[f,2])and(x>min) do
   begin
    inc(c[f,1]);
    inc(min);
   end;
   inc(f);
  end;
 for f:=1 to n do
  write(c[f,1],' ');
 end else writeln('NO');
end.