var a:array[1..100,0..10100]of longint;
    b:array[1..10000]of longint;
    n,m,i,f,min,g:longint;log:boolean;c:char;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  log:=false;
  for f:=1 to m do
  begin
   read(c);
   if c='0' then a[i,f]:=0 else
   begin
    a[i,f]:=1;log:=true;
    g:=f-1;
    while (g>0)and(a[i,g]=0) do begin a[i,g]:=a[i,g+1]+1;dec(g);end;
   end;
  end;
  if not(log) then begin writeln('-1');halt(0);end;
  for f:=2 to m do if (a[i,f-1]<a[i,f])or(a[i,f]=0) then a[i,f]:=a[i,f-1]+1;
  a[i,m+1]:=a[i,1];f:=m;
  while (f>0)and(a[i,f]>a[i,f+1])or(a[i,f]=0) do begin a[i,f]:=a[i,f+1]+1;dec(f);end;
  a[i,0]:=a[i,m];f:=1;
  while (f<m+1)and(a[i,f]>a[i,f-1])or(a[i,f]=0) do begin a[i,f]:=a[i,f-1]+1;inc(f);end;
  readln;
 end;
 for i:=1 to n do
  for f:=1 to m do
   b[f]:=b[f]+a[i,f];
 min:=1;
 for i:=1 to m do
  if b[min]>b[i] then min:=i;
 writeln(b[min]-n);
end.