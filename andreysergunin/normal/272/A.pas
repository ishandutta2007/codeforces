var n,a,s,k:int64;
    i:longint;
begin
read (n);
for i:=1 to n do
     begin
      read (a);
      s:=s+a;
     end;
for i:=1 to 5 do if (s+i-1) mod (n+1)<>0 then k:=k+1;
write (k);
end.