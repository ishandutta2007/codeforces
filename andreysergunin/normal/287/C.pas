var n,i:longint;
    a:array[1..100000] of longint;
begin
read (n);
if (n mod 4 =2) or (n mod 4 = 3) then write ('-1');
if (n mod 4 =0) then
    begin
     for i:=1 to n div 4 do
         begin
          a[2*i-1]:=2*i;
          a[2*i]:=n-2*i+2;
          a[n-2*i+2]:=n-2*i+1;
          a[n-2*i+1]:=2*i-1;
         end;
     for i:=1 to n do write (a[i],' ');
    end;
if (n mod 4 =1) then
    begin
     a[(n+1)div 2]:=(n+1)div 2;
     for i:=1 to n div 4 do
         begin
          a[2*i-1]:=2*i;
          a[2*i]:=n-2*i+2;
          a[n-2*i+2]:=n-2*i+1;
          a[n-2*i+1]:=2*i-1;
         end;
     for i:=1 to n do write (a[i],' ');
    end;

end.