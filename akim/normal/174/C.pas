var b:array[0..100000,1..2]of longint;
    x:array[1..100000,1..3]of longint;
    a,n,i,f,s,t:longint;
begin
 readln(n);
 f:=0;s:=0;b[0,1]:=0;b[0,2]:=0;
 for i:=1 to n do
 begin
  read(a);
  while a<b[f,1] do 
  begin
   if b[f-1,1]<a then begin inc(s);x[s,3]:=b[f,1]-a;t:=t+x[s,3];x[s,1]:=b[f,2];x[s,2]:=i-1;b[f,1]:=a;end
                  else begin inc(s);x[s,3]:=b[f,1]-b[f-1,1];t:=t+x[s,3];x[s,1]:=b[f,2];x[s,2]:=i-1;dec(f);end;
  end;
  if a>b[f,1] then begin inc(f);b[f,1]:=a;b[f,2]:=i;end;
 end;
 a:=0;i:=n;
 while a<b[f,1] do 
 begin
  inc(s);x[s,3]:=b[f,1]-b[f-1,1];t:=t+x[s,3];x[s,1]:=b[f,2];x[s,2]:=i;dec(f);
 end;
 writeln(t);
 for i:=1 to s do
  for f:=1 to x[i,3] do
   writeln(x[i,1],' ',x[i,2]);
end.