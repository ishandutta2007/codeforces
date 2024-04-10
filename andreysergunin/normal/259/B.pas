var a:array [1..3,1..3] of longint;
    i,j,n:longint;
begin
for i:=1 to 3 do
        for j:=1 to 3 do
                read (a[i,j]);
for i:=1 to 3 do
        for j:=1 to 3 do
                n:=n+a[i,j];
n:=n div 2;
a[1,1]:=n-a[1,2]-a[1,3];
a[2,2]:=n-a[2,1]-a[2,3];
a[3,3]:=n-a[3,2]-a[3,1];
for i:=1 to 3 do
        begin
        for j:=1 to 3 do write (a[i,j],' ');
        writeln;
        end;
end.