var s,l,k:ansistring;
    a,b:array[1..200002] of byte;
    i,m:longint;
begin
read (s);
if length (s)=1 then write (s)
        else
        begin
         l:=s[1]+s[2];
         m:=0;
         for i:=3 to length (s) do if (s[i]<>s[i-1]) or (s[i]<>s[i-2]) then l:=l+s[i];
         for i:=1 to length (l)-1 do if l[i]=l[i+1] then a[i]:=1;
         for i:=1 to length (l) do
                begin
                 if ((a[i]=1) and (b[i]=0)) then
                        begin
                         b[i+2]:=1;
                         k:=k+l[i];
                        end;
                 if a[i]=0 then k:=k+l[i];
                end;


        end;
write (k);
end.