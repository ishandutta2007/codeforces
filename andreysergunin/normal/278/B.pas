var s:array[1..30] of string;
    n,v,i,j,w:integer;
    f,t:boolean;
begin
readln (n);
for i:=1 to n do readln (s[i]);
f:=true;
t:=true;

for v:=1 to 26 do
        begin
         f:=true;
         for i:=1 to n do
                for j:=1 to length (s[i]) do
                  begin
                  if ord(s[i][j])=ord ('a')+v-1 then f:=false;
                  end;
         if f and t then
                begin
                 t:=false;
                 write (chr (ord('a')+v-1));
                end;
        end;
if t then
        begin
        for v:=1 to 26 do
                for w:=1 to 26 do
                        begin
                         f:=true;
                         for i:=1 to n do
                                for j:=1 to length (s[i])-1 do
                                        begin
if (ord(s[i][j])=ord ('a')+v-1) and (ord(s[i][j+1])=ord ('a')+w-1) then f:=false;
                                        end;
                         if f and t then
               begin
               t:=false;
               write (chr (ord('a')+v-1),chr (ord('a')+w-1));
               end;
                        end;
          
        end;

end.