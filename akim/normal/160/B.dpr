var a,b:array[1..100]of longint;
    n,i,f,x:longint;
    log:boolean;
    c:char;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(c);
  case(c)of
  '0':a[i]:=0;
  '1':a[i]:=1;
  '2':a[i]:=2;
  '3':a[i]:=3;
  '4':a[i]:=4;
  '5':a[i]:=5;
  '6':a[i]:=6;
  '7':a[i]:=7;
  '8':a[i]:=8;
  '9':a[i]:=9;
  end;
 end; 
 for i:=1 to n do
 begin
  read(c);
  case(c)of
  '0':b[i]:=0;
  '1':b[i]:=1;
  '2':b[i]:=2;
  '3':b[i]:=3;
  '4':b[i]:=4;
  '5':b[i]:=5;
  '6':b[i]:=6;
  '7':b[i]:=7;
  '8':b[i]:=8;
  '9':b[i]:=9;
  end;
 end;
 for i:=1 to n-1 do
  for f:=i+1 to n do
  begin
   if a[i]>a[f] then begin
                      x:=a[i];
                      a[i]:=a[f];
                      a[f]:=x;
                     end;
   if b[i]>b[f] then begin
                      x:=b[i];
                      b[i]:=b[f];
                      b[f]:=x;
                     end;
  end;
 if a[1]>b[1] then log:=true else
 if a[1]<b[1] then log:=false else
 begin writeln('NO');halt(0);end;
 for i:=1 to n do
 begin
  if (log)and(a[i]<=b[i]) then begin writeln('NO');halt(0);end;
  if (not(log))and(a[i]>=b[i]) then begin writeln('NO');halt(0);end;
 end;
 writeln('YES');
end.