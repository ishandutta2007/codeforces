var n,k,j,i,t:longint;
    a,b:array [1..900] of integer;
begin
read (n,k);
for i:=1 to n*k do b[i]:=0;
for i:=1 to k do read (a[i]);
for i:=1 to k do b[a[i]]:=1;
t:=0;
for i:=1 to k do
    begin
    j:=1;
   
    while j<n do
        begin
        t:=t+1;
        if b[t]<>1 then
            begin
            j:=j+1;
            write (t,' ');
            end;
      
        end;
    writeln (a[i],' ');  
    end;

end.