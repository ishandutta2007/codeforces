import qualified Data.ByteString.Char8 as B
import Control.Monad
import Control.Applicative
import System.IO
import Data.Bits
import Data.Maybe

main = do
        hSetBuffering stdout (BlockBuffering (Just 65536))
        n <- fst . fromMaybe undefined . B.readInteger <$> B.getLine
        if n==1 then
                print 1
        else do
                let l = log2 n 
                let d = max 0 (round ( fromIntegral l * logBase 3 2 ) - 4)
                let n' = (n-1) `div` (3^d) + 1
                print $ 3*d + f n'

log2 n = bin (\i -> n >= bit i) 0 (10^7)

bin f lo hi 
        | lo+1 == hi = lo
        | f mi = bin f mi hi
        | True = bin f lo mi
        where mi = (lo+hi)`div`2

log3 1 = 0
log3 n = 1 + log3 ((n+2)`div`3)

f n = minimum [
        3*log3 n,
        3*log3((n+1)`div`2)+2,
        3*log3((n+3)`div`4)+4 ]