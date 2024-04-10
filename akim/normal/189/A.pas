var a:array[1..8000]of longint;
    n,x,y,z,i:longint;
begin
 readln(n,x,y,z);
 a[x]:=1;
 for i:=1 to n do begin if (a[i]>0)and(a[i+x]<a[i]+1) then a[i+x]:=a[i]+1;end;
 if a[y]=0 then a[y]:=1;
 for i:=1 to n do begin if (a[i]>0)and(a[i+y]<a[i]+1) then a[i+y]:=a[i]+1;end;
 if a[z]=0 then a[z]:=1;
 for i:=1 to n do begin if (a[i]>0)and(a[i+z]<a[i]+1) then a[i+z]:=a[i]+1;end;
 writeln(a[n]);
end.